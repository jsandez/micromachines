#include "includes/cliente/utils/ConfigCliente.h"
#include "includes/cliente/HiloGrabador.h"
#include "src/cliente/grabador/ffmepg/video/output_video.cpp"
#include "src/cliente/grabador/ffmepg/common/output_format.cpp"

#include <ctime>


HiloGrabador::HiloGrabador(){}

void HiloGrabador::correr(){
    time_t t = std::time(0);
	long int ahora = static_cast<long int> (t);
	std::string  nombreGrabacion = std::to_string(ahora) + std::string(".") + CONFIG_CLIENTE.formatoGrabadora();
    OutputFormat fmt(nombreGrabacion);
    AVRational frame_rate = { 1, static_cast<int>(CONFIG_CLIENTE.fpsGrabadora()) };
    OutputVideo videoOutput(fmt, frame_rate, CONFIG_CLIENTE.anchoGrabadora(), CONFIG_CLIENTE.altoGrabadora(), AV_PIX_FMT_RGB24);
    fmt.open();				
	while (seguirCorriendo_){
		std::vector<char> linea;
        lineas_rgb_.swap();
		lineas_rgb_.get(linea);
        videoOutput.rgb_line_to_frame(linea.data());
        videoOutput.write_frame();		
	}   
	fmt.write_trailer();
	// Reinicio el doble buffer
	lineas_rgb_ = DobleBuffer<std::vector<char>>();
}


void HiloGrabador::detener(){
    seguirCorriendo_ = false;
}

void HiloGrabador::insertar_linea_rgb(std::vector<char>& linea){
    lineas_rgb_.set(linea);
}