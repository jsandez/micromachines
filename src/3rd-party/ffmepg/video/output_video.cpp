#ifndef	__OUTPUT_VIDEO_H___
#define __OUTPUT_VIDEO_H___


#include "../common/output_stream.cpp"
#include "video_codec.cpp"


class OutputVideo : public OutputStream {
	public:
		OutputVideo(OutputFormat &fmt, AVRational avr,
								int w, int h, AVPixelFormat pix) : OutputStream(fmt) {
			try{
				st->time_base = avr;
				enc = new VideoCodec(fmt.get_video_codec_id(), avr, frame,
										 w, h, pix, fmt.is_flag_set(AVFMT_GLOBALHEADER));
				
				reinterpret_cast<VideoCodec *>(enc)->copy_parameters(st);				
			} catch (std::runtime_error &e){
				throw std::runtime_error(e);
			}
		}


		void rgb_line_to_frame(const char * v){
			reinterpret_cast<VideoCodec *>(enc)->write_rgb_frame(frame, v, current_pts);
			current_pts ++;
		}


		~OutputVideo(){}
};


#endif
