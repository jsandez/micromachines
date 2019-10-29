#ifndef	__OUTPUT_VIDEO_H___
#define __OUTPUT_VIDEO_H___


#include "output_stream.cpp"



class OutputVideo : public OutputStream {
	private:
		SwrContext * swr;
	public:
		OutputVideo(OutputFormat &fmt, AVRational avr,
								int w, int h, int pix) : OutputStream(fmt) {
			st->time_base = avr;
			enum AVcodecID id = fmt.get_video_codec_id();
			enc = VideoCodec(id, avr, h, w, pix);
		}

		virtual void write_frame(const std::vector<char>& v){
			enc.rgb_vector_to_yuv(frame, v, current_pts);
			current_pts++;
			
		}

		~OutputVideo(){}
}


#endif
