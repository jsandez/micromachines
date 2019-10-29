#ifndef	__OUTPUT_FORMAT_H___
#define __OUTPUT_FORMAT_H___


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


class OutputFormat {
	private:
	    AVFormatContext *ctx;
	    std::string& filename;
	public:
		OutputFormat(const std::string& file): filename(file){
		    avformat_alloc_output_context2(&ctx, NULL, NULL, filename);
	        if (!oc) {
	        	// Si no se encuentra el formato del archivo, se usa MPEG
		        avformat_alloc_output_context2(&oc, NULL, "mpeg", filename);
		    }
		    if (!oc){
		    	throw std::runtime_error("No se pudo alocar el contexto del formato del archivo");
		    }

		}

		AVStream * get_new_stream(){
			AVStream * st = avformat_new_stream(ctx, NULL);
			st->id = ctx->nb_streams-1;
			return st;
		}

		void open(){
		    av_dump_format(oc, 0, filename, 1);
		    int ret;
		    if (!(ctx->oformat->flags & AVFMT_NOFILE)) {
		    	ret = avio_open(&ctx->pb, filename, AVIO_FLAG_WRITE);
		        if (ret < 0){
		        	std::string err(av_err2str(ret));
		        	throw std::runtime_error("No se pudo abrir el archivo" + err);
		        }
	    	}

			// EN VEZ DE NULL SE PUEDEN AGREGAR OPCIONES
		    ret = avformat_write_header(ctx, NULL);
		    if (ret < 0){
	        	std::string err(av_err2str(ret));
	        	throw std::runtime_error("No se pudo escribir el header" + err);
	        }

		}

		enum AVCodecID get_video_codec_id(){
			return ctx->oformat->video_codec;
		}

		enum AVCodecID get_audio_codec_id(){
			return ctx->oformat->audio_codec;
		}

		void write_trailer(){
			if (av_write_trailer(ctx) < 0){
				throw std::runtime_error("No se pudo escribir el trailer");
			}
		}

		~OutputFormat(){
		    if (!(ctx->oformat->flags & AVFMT_NOFILE)){
		        avio_closep(&ctx->pb);    	
		    }
			if (ctx){
			    avformat_free_context(ctx);
			}
		}
};

#endif