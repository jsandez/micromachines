#ifndef	__CODEC_H___
#define __CODEC_H___


#include <iostream.h>
#include <string>
#include <math>
#include <exception>

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
		}

		Codec(Codec&& rhs){
			this->enc = rhs->enc;
			rhs->enc = NULL;
		}

		Codec& operator=(Codec&& rhs){
			this->enc = rhs->enc;
			rhs->enc = NULL;
			return *this;			
		}

		Codec(const Codec& rhs) = delete;
		Codec& operator=(const Codec& rhs) = delete;


		~Codec(){
			if (enc){
				avcodec_free_context(enc);
			}
		}
};

#endif
