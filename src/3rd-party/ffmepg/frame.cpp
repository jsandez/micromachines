#ifndef	__FRAME_H___
#define __FRAME_H___


#include <iostream.h>
#include <string>
#include <math>
#include <exception>
#include <vector>

#include <libavutil/avassert.h>
#include <libavutil/channel_layout.h>
#include <libavutil/opt.h>
#include <libavutil/mathematics.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>

class VideoCodec {
    private:
	    AVFrame * fr;
	public:
		Frame() {
			fr = av_frame_alloc();
			if (!fr){
				throw std::runtime_error("No se pudo inicializar frame");
			}
		}

		void AudioFrame(enum AVPixelFormat pix_fmt, int width, int height){
		    fr->format = pix_fmt;
		    fr->width  = width;
		    fr->height = height;
		    if (av_frame_get_buffer(fr, 0) < 0){
		    	throw std::runtime_error("No se pudo obtener buffer para el audio");
		    }

		}

		void make_writable(){
		    if (av_frame_make_writable(fr) < 0){
		    	throw std::runtime_error("No se pudo asegurar la escritura del Frame");
		    }
		}


		const AVFrame * get_frame() const {
			return fr;
		}



		void fill_rgb_vector(SwsContext * ctx, const std::vector<char>& v,
																int width, int pts){
			sws_scale(ctx, (const uint8_t * const *) &buff.data(),
				width * 3, 0, this->fr->height, this->fr->data, this->fr->linesize);
			this->fr->pts = pts;
		}

		void VideoFrame(enum AVSampleFormat sample_fmt,
                                  uint64_t channel_layout,
                                  int sample_rate, int nb_samples){
			fr->format = sample_fmt;
		    fr->channel_layout = channel_layout;
		    fr->sample_rate = sample_rate;
		    fr->nb_samples = nb_samples;
		    if (av_frame_get_buffer(fr, 0) < 0){
		    	throw std::runtime_error("No se pudo obtener buffer para el video");
		    }
		}


		Frame(const Frame&) = delete;
		Frame& operator=(const Frame&) = delete;
		
		Frame(Frame&& rhs){
			rhs.fr = this->fr;
			this->fr = NULL;
		}
		Frame& operator=(Frame&& rhs){
			rhs.fr = this->fr;
			this->fr = NULL;
			return *this;
		}


		~Frame(){
			if (fr){
				av_frame_free(&fr);
			}
		}
};

#endif
