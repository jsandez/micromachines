#include "includes/cliente/grabador/HiloGrabador.h"

#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/grabador/ffmpeg/output_video.h"
#include "includes/cliente/grabador/ffmpeg/output_format.h"

#include <ctime>

#include <thread>
#include <chrono>

void HiloGrabador::correr(){
    time_t t = std::time(0);
	long int ahora = static_cast<long int> (t);
	std::string  nombreGrabacion = std::to_string(ahora) + std::string(".") + CONFIG_CLIENTE.formatoGrabadora();
    OutputFormat fmt(nombreGrabacion);
    AVRational frame_rate = { 1, static_cast<int>(CONFIG_CLIENTE.fpsGrabadora()) };
    OutputVideo videoOutput(fmt, frame_rate, CONFIG_CLIENTE.anchoGrabadora(), CONFIG_CLIENTE.altoGrabadora(), AV_PIX_FMT_RGB24);
    fmt.open();				
	while (seguirCorriendo_){
		std::vector<char> linea = lineas_rgb_.get();
        videoOutput.rgb_line_to_frame(linea.data());
        videoOutput.write_frame();
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
	}   
	fmt.write_trailer();
	// Reinicio el doble buffer
    //FIXME: HACER UN VACIAR, no se pueden reasignar/mover mutexes. En realidad no es necesario vaciarlo
	//lineas_rgb_ = DobleBuffer<std::vector<char>>();
}


void HiloGrabador::detener(){
    seguirCorriendo_ = false;
}

DobleBuffer<std::vector<char>>& HiloGrabador::getBuffer() {
    return lineas_rgb_;
}
