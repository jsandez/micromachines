#ifndef	__OUTPUT_VIDEO_H___
#define __OUTPUT_VIDEO_H___


#include "output_stream.cpp"
#include "video_codec.cpp"


class OutputVideo : public OutputStream {
	public:
		OutputVideo(OutputFormat &fmt, AVRational avr,
								int w, int h, AVPixelFormat pix) : OutputStream(fmt) {
			try{
				st->time_base = avr;
				enc = new VideoCodec(fmt.get_video_codec_id(), avr, frame,
										 h, w, pix, fmt.is_flag_set(AVFMT_GLOBALHEADER));
				
				reinterpret_cast<VideoCodec *>(enc)->copy_parameters(st);				
			} catch (std::runtime_error &e){
				throw std::runtime_error(e);
			}
		}


		void rgb_line_to_frame(char * v){
			reinterpret_cast<VideoCodec *>(enc)->write_rgb_frame(frame, v, current_pts);
			current_pts ++;
		}


		virtual void write_frame(){
			try {
			    enc->encode_frame(frame);
			    while (true){
					AVPacket pkt = { 0 };    	
				    av_init_packet(&pkt);
				    const AVRational *time_base;
				    if (!enc->get_packet(&pkt, time_base)){
				    	break;
				    }
			        av_packet_rescale_ts(&pkt, *time_base, st->time_base);
				    pkt.stream_index = st->index;

				    //write
					if (fmt.write_pkt(&pkt)){
						throw std::runtime_error("No se pudo escribir paquete");
					}	
			    }
			} catch (std::runtime_error &e){
				throw std::runtime_error(e);
			}
		}

		~OutputVideo(){}
};


#endif
