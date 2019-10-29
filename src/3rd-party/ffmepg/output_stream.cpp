#ifndef	__OUTPUT_STREAM_H___
#define __OUTPUT_STREAM_H___


#include <iostream.h>
#include <string>
#include <math>


#include "frame.cpp"
#include "codec.cpp"
#include "output_format.cpp"

#include <libavutil/avassert.h>
#include <libavutil/channel_layout.h>
#include <libavutil/opt.h>
#include <libavutil/mathematics.h>
#include <libavutil/timestamp.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libswresample/swresample.h>

#define STREAM_DURATION   10.0
#define STREAM_FRAME_RATE 25 /* 25 images/s */
#define STREAM_PIX_FMT    AV_PIX_FMT_YUV420P /* default pix_fmt */

#define SCALE_FLAGS SWS_BICUBIC

class OutputStream {
    protected:
	    AVStream *st;
	    Codec enc;
	    /* pts of the next frame that will be generated */
	    int64_t current_pts = 0;
	    OutputFormat &fmt;
	    Frame frame;
	public:
		OutputStream(OutputFormat &fmt) : fmt(fmt){
			st = fmt.get_new_stream();
		}

		virtual void write_frame(const std::vector<char>&) = delete;

		AVStream * get_stream(){
			return st;
		}
		~OutputStream(){}
};

#endif
