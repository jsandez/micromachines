#ifndef	__CODEC_VIDEO_H___
#define __CODEC_VIDEO_H___


#include <iostream.h>
#include <string>
#include <math>
#include <exception>
#include "codec.cpp"

#include <libavutil/avassert.h>
#include <libavutil/channel_layout.h>
#include <libavutil/opt.h>
#include <libavutil/mathematics.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>

class VideoCodec : public Codec {
    private:
	    struct SwsContext *sws_ctx = NULL;
	public:
		VideoCodec(enum AVcodecID id, AVRational avr, 
							 int height, int width, int pix_fmt) : Codec(id) {
			enc->codec_id = id;
	        enc->bit_rate = 400000;

	        /* Resolution must be a multiple of two. */
	        enc->width    = width;
	        enc->height   = height;
	        
        /* timebase: This is the fundamental unit of time (in seconds) in terms
         * of which frame timestamps are represented. For fixed-fps content,
         * timebase should be 1/framerate and timestamp increments should be
         * identical to 1. */
	        enc->time_base = avr;
	        enc->gop_size = 10; /* emit one intra frame every testing frames at most */
	        enc->pix_fmt = pix_fmt;
	        if (enc->codec_id == AV_CODEC_ID_MPEG2VIDEO) {
	            /* just for testing, we also add B-frames */
	            enc->max_b_frames = 2;
	        }
	        if (enc->codec_id == AV_CODEC_ID_MPEG1VIDEO) {
	            /* Needed to avoid using macroblocks in which some coeffs overflow.
	             * This does not happen with normal video, it just happens here as
	             * the motion of the chroma plane does not match the luma plane. */
	            enc->mb_decision = 2;
			}

			if (enc->codec_id == AV_CODEC_ID_H264) {
			    enc->profile = FF_PROFILE_H264_BASELINE;
			    av_opt_set(enc->priv_data, "preset", "slow", 0);
			}

			if (avcodec_parameters_from_context(
							vid.get_stream()->codecpar, enc) < 0){
				throw std::runtime_error("No se pudieron copiar
									 los parametros del contexto al stream");
			}

		    if (pix_fmt != AV_PIX_FMT_YUV420P) {
	        /* as we only generate a YUV420P picture, we must convert it
	         * to the codec pixel format if needed */
		        sws_ctx = sws_getContext(width, height, AV_PIX_FMT_YUV420P,
		                                      width, height, pix_fmt,
		                                      SWS_BICUBIC, NULL, NULL, NULL);
		        if (!sws_ctx) {
		            throw std::runtime_error("No se pudo iniciar 
            								el contexto de converión de video");
		        }
			}
		}

		virtual void encode(AVPacket * pkt, const Frame& f){
 				avcodec_encode_video2(enc, pkt, f.get_frame(), &got_packet);

		}

		void rgb_vector_to_yuv(Frame& dest, const std::vector<char>& v, int pts){
			dest.fill_rgb_vector(sws_ctx, v, enc->width, pts);
		}

		~VideoCodec(){
			if (sws_ctx){
			    sws_freeContext(sws_ctx);
			}
		}
};

#endif
