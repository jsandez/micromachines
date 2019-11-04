#ifndef	__CODEC_VIDEO_H___
#define __CODEC_VIDEO_H___


#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include "../common/codec.cpp"
#include "../common/frame.cpp"



extern "C" {
	#include <libswscale/swscale.h>
}


class VideoCodec : public Codec {
    private:
	    struct SwsContext *sws_ctx = NULL;
	public:
		VideoCodec(enum AVCodecID id, AVRational avr, Frame& fr,
					int width, int height, AVPixelFormat pix_fmt, bool header_flag) : Codec(id) {
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

			if (header_flag){
		        enc->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
			}

			if (enc->codec_id == AV_CODEC_ID_H264) {
			    enc->profile = FF_PROFILE_H264_BASELINE;
			    av_opt_set(enc->priv_data, "preset", "slow", 0);
			}

	        enc->pix_fmt = codec->pix_fmts[0]; /* best quality format for codec*/

	        Codec::open();


	        sws_ctx = sws_getContext(width, height, pix_fmt,
	                                      width, height, enc->pix_fmt,
	                                      SWS_BICUBIC, NULL, NULL, NULL);
	        if (!sws_ctx) {
	            throw std::runtime_error("No se pudo iniciar el contexto de converión de video");
	        }

			fr.VideoFrame(enc->pix_fmt, width, height);
		}

		void copy_parameters(AVStream * st){
			if (avcodec_parameters_from_context(
							st->codecpar, enc) < 0){
				throw std::runtime_error("No se pudieron copiar los parametros del contexto al stream");
			}
		}

		void write_rgb_frame(Frame& dest, const char * data, int pts){
			dest.fill_rgb(sws_ctx, data, enc->width, pts);
		}


		VideoCodec(const VideoCodec&) = delete;
		VideoCodec& operator=(const VideoCodec&) = delete;

		VideoCodec(VideoCodec&& rhs) : Codec(std::move(rhs)){
			this->sws_ctx = rhs.sws_ctx;
			rhs.sws_ctx = NULL;
		}

		VideoCodec& operator=(VideoCodec&& rhs) = delete;


		~VideoCodec(){
			if (sws_ctx){
			    sws_freeContext(sws_ctx);
			}
		}
};

#endif
