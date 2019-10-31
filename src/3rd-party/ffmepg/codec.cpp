#ifndef	__CODEC_H___
#define __CODEC_H___


#include <iostream>
#include <string>
#include <cmath>
#include <exception>
#include "frame.cpp"


#include <libavutil/avassert.h>
#include <libavutil/channel_layout.h>
#include <libavutil/opt.h>
#include <libavutil/mathematics.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>


class Codec {
    protected:
	    AVCodecContext *enc;
	public:
		Codec(){}

		Codec(enum AVCodecID id){
			AVCodec * codec = avcodec_find_encoder(id);
			if (!codec) {
				throw std::runtime_error("Encoder no encontrado.");
			}
		    enc = avcodec_alloc_context3(codec);
		    if (!enc) {
		    	throw std::runtime_error("No se pudo alocar el contexto del encoder");
		    }

		    // NULL pero se puede agregar un diccionario de opciones
	        if (avcodec_open2(enc, codec, NULL) < 0){
		    	throw std::runtime_error("No se puedo abrir el encoder");	        	
	        }

	        enc->pix_fmt = codec->pix_fmts[0]; /* best quality format for codec*/

		}


		void encode_frame(const Frame& f){
	        if (avcodec_send_frame(enc, f.get_frame())) {
		        throw std::runtime_error("Error al enviar frame");
		    }
		}

		int get_packet(AVPacket * pkt, const AVRational *time_base){
	        int ret = avcodec_receive_packet(enc, pkt);
	        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
	            return 0;
	        else if (ret < 0) {
	            throw std::runtime_error("Error al codificar");
	        }
	        time_base = (const AVRational *) &enc->time_base;
		    return 1;
		}



		Codec(Codec&& rhs){
			this->enc = rhs.enc;
			rhs.enc = NULL;
		}

		Codec& operator=(Codec&& rhs){
			this->enc = rhs.enc;
			rhs.enc = NULL;
			return *this;			
		}

		Codec(const Codec& rhs) = delete;
		Codec& operator=(const Codec& rhs) = delete;


		~Codec(){
			if (enc){
				avcodec_free_context(&enc);
			}
		}
};

#endif
