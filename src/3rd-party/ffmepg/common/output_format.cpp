#ifndef	__OUTPUT_FORMAT_H___
#define __OUTPUT_FORMAT_H___


#include <iostream>
#include <string>
#include <cmath>
#include <exception>


extern "C" {
	#include <libavutil/avassert.h>
	#include <libavformat/avformat.h>
}


class OutputFormat {
	private:
	    AVFormatContext *ctx;
	    std::string filename;
	public:
		OutputFormat(const std::string& file): filename(file){
		    avformat_alloc_output_context2(&ctx, NULL, NULL, filename.c_str());
	        if (!ctx) {
	        	// Si no se encuentra el formato del archivo, se usa MPEG
		        avformat_alloc_output_context2(&ctx, NULL, "mpeg", filename.c_str());
		    }
		    if (!ctx){
		    	throw std::runtime_error("No se pudo alocar el contexto del formato del archivo");
		    }

		}

		AVStream * get_new_stream(){
			AVStream * st = avformat_new_stream(ctx, NULL);
			st->id = ctx->nb_streams-1;
			return st;
		}

		bool is_flag_set(int flag){
			return ctx->oformat->flags & AVFMT_GLOBALHEADER;
		}


		int write_pkt(AVPacket * pkt){
    		return av_interleaved_write_frame(ctx, pkt);
		}


		void open(){
		    av_dump_format(ctx, 0, filename.c_str(), 1);
		    if (!(ctx->oformat->flags & AVFMT_NOFILE)) {
		        if (avio_open(&ctx->pb, filename.c_str(), AVIO_FLAG_WRITE) < 0){
		        	throw std::runtime_error("No se pudo abrir el archivo");
		        }
	    	}

			// EN VEZ DE NULL SE PUEDEN AGREGAR OPCIONES
		    if (avformat_write_header(ctx, NULL) < 0){
	        	throw std::runtime_error("No se pudo escribir el header");
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