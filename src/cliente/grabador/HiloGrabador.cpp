#include "includes/cliente/grabador/HiloGrabador.h"

extern "C" {
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/grabador/ffmpeg/OutputFormat.h"
#include "includes/cliente/grabador/ffmpeg/FormatContext.h"

#include <ctime>

#include <thread>
#include <chrono>

int BUFFER_WIDTH = 640;
int BUFFER_HEIGHT = 480;

void HiloGrabador::correr(){
    time_t t = std::time(0);
	long int ahora = static_cast<long int> (t);
	std::string  nombreGrabacion = std::to_string(ahora) + std::string(".") + CONFIG_CLIENTE.formatoGrabadora();
    
    av_register_all();
    FormatContext context;
    OutputFormat videoOutput(context, nombreGrabacion);

    SwsContext * ctx = sws_getContext(BUFFER_WIDTH, BUFFER_HEIGHT,
                                  AV_PIX_FMT_RGB24, BUFFER_WIDTH, BUFFER_HEIGHT,
                                  AV_PIX_FMT_YUV420P, 0, 0, 0, 0);

    
    while (seguirCorriendo_) {
        std::vector<char> lineaEscribir = lineas_rgb_.get(false);
        videoOutput.writeFrame(lineaEscribir.data(), ctx);
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
    videoOutput.close();
    // Libero escalador
    sws_freeContext(ctx);
}


void HiloGrabador::detener(){
    seguirCorriendo_ = false;
}

DobleBuffer<std::vector<char>>& HiloGrabador::getBuffer() {
    return lineas_rgb_;
}
