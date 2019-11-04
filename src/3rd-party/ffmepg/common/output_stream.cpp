#ifndef	__OUTPUT_STREAM_H___
#define __OUTPUT_STREAM_H___


#include <iostream>
#include <string>
#include <cmath>


#include "frame.cpp"
#include "codec.cpp"
#include "output_format.cpp"


extern "C" {
	#include <libavutil/avassert.h>
	#include <libavformat/avformat.h>
	#include <libavutil/opt.h>
	#include <libavutil/mathematics.h>
	#include <libavutil/timestamp.h>
}


#define STREAM_DURATION   10.0
#define STREAM_FRAME_RATE 25 /* 25 images/s */
#define STREAM_PIX_FMT    AV_PIX_FMT_YUV420P /* default pix_fmt */

#define SCALE_FLAGS SWS_BICUBIC

class OutputStream {
    protected:
	    AVStream *st;
	    Codec * enc;
	    AVPacket * pkt;
	    /* pts of the next frame that will be generated */
	    int64_t current_pts = 0;
	    OutputFormat &fmt;
	    Frame frame;
	public:
		OutputStream(OutputFormat &fmt) : fmt(fmt){
			st = fmt.get_new_stream();
			pkt = av_packet_alloc();
		}

		virtual void write_frame(){
			try {
			    enc->encode_frame(frame);
			    while (true){
				    AVRational time_base;
				    if (!enc->get_packet(pkt, &time_base)){
				    	break;
				    }
			        av_packet_rescale_ts(pkt, time_base, st->time_base);
			       	pkt->stream_index = st->index;
				    //write
					if (fmt.write_pkt(pkt)){
						throw std::runtime_error("No se pudo escribir paquete");
					}
			        av_packet_unref(pkt);
			    }
			} catch (std::runtime_error &e){
				throw std::runtime_error(e);
			}
		}

		~OutputStream(){
		    av_packet_free(&pkt);
		}
};

#endif
