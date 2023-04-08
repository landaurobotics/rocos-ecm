/*-----------------------------------------------------------------------------
 * EcFlags.cpp
 * Author                   Yang Luo , luoyang@sia.cn
 * Last Modification Date   2023.04.04 18:00
 *---------------------------------------------------------------------------*/
#include <regex>
#include "EcFlags.h"

//! @brief the path of EtherCAT configuration file(YAML). Default value is "/etc/rocos-ecm/ecat_config.yaml"
DEFINE_string(config, "/opt/rocos/ecm/config/ecat_config.yaml", "Path to ecat_config file in YAML format.");

//! @brief the path of eni file(EtherCAT Network Information). Default value is "/etc/rocos-ecm/eni.xml"
DEFINE_string(eni, "/opt/rocos/ecm/config/eni.xml", "Path to ENI file in XML format.");

//! @brief the running duration of Ec-Master in msec, 0 is forever
DEFINE_int32(duration, 0, "Time in msec, 0 = forever, Running duration in msec. When the time expires, the application exits completely.");

//! @brief Bus cycle time in usec. Default is 1000
DEFINE_int32(cycle, 1000, "Bus cycle time in μsec. Specifies the bus cycle time. Defaults to 1000μs (1ms).");

//! @brief Verbosity level
DEFINE_int32(verbose, 3, "Verbosity level: 0=off (default), 1..n=more messages. The verbosity level specifies how much console output messages will be generated by the demo application. A high verbosity level leads to more messages.");

//! @brief Which CPU the Ec-Master use
DEFINE_int32(cpuidx, 0, "0 = first CPU, 1 = second, .... The CPU affinity specifies which CPU the demo application ought to use.");

//! @brief Measurement in us for all EtherCAT jobs
DEFINE_bool(perf, true, "Enable max. and average time measurement in μs for all EtherCAT jobs (e.g. ProcessAllRxFrames).");

//! @brief Clock period in μs
DEFINE_int32(auxclk, 0, "Clock period in μs, must greater than 10, otherwise auxclk is disable. (if supported by Operating System).");

//! @brief The remote API Server port
DEFINE_int32(sp, 0xFFFF, "If platform has support for IP Sockets, this commandline option enables the Remote API Server to be started with the EcMasterDemo. The Remote API Server is going to listen on TCP Port 6000 (or port parameter if given) and is available for connecting Remote API Clients. This option is included for attaching the EC-Lyser Application to the running master.");

//! @brief Log file prefix
DEFINE_string(log, "", "Use given file name prefix for log files.");

//! @brief Flash outputs address.
DEFINE_int32(flash, 0xFFFF, "Flash outputs address. 0=all, >0 = slave address");

//! @brief DC mode
DEFINE_int32(dcmmode, 1, "Set DCM mode. 0 = off, 1 = busshift, 2 = mastershift, 3 = linklayerrefclock, 4 = masterrefclock, 5 = dcx");

//! @brief Disable DCM control loop for diagnosis
DEFINE_bool(ctloff, false, "Disable DCM control loop for diagnosis. ");

//! @brief Intel network card instances and mode
DEFINE_int32(link, 0, "Link layer selection: 0 = Intel 8254x, 1 = Intel 8255x. The link layer selection specifies which link layer is used by the demo application. The default is Intel 8254x. ");
DEFINE_string(instance, "01:00.0", "Device instance 1=first, 2=second. The device instance specifies which network card is used by the demo application. The default is the first network card. ");
DEFINE_int32(mode, 1, "Mode 0 = Interrupt mode, 1= Polling mode. The mode specifies which mode is used by the demo application. The default is interrupt mode. ");

DEFINE_string(state, "op", "The request state of EtherCAT slaves. value can be init/preop/safeop/op The default is op. ");


//DEFINE_string(i8254x, "1 1", "<instance>: Device instance 1=first, 2=second; <mode>: Mode 0 = Interrupt mode, 1= Polling mode");
//static bool Validate8254x(const char* flagname, const std::string& value) {
//    std::regex ws_re("\\s+"); // whitespace
//    std::vector<std::string> v(std::sregex_token_iterator(value.begin(), value.end(), ws_re, -1), std::sregex_token_iterator());
//    if(v.size() != 2) {
//        printf("Invalid value for --%s: %s\n", flagname, value.c_str());
//        return false;
//    }
//    int instance = std::stoi(v[0]);
//    int mode = std::stoi(v[1]);
//    if((instance < 1) || (instance > 2) || (mode < 0) || (mode > 1)) {
//        printf("Invalid value for --%s: %s\n", flagname, value.c_str());
//        return false;
//    }
//    else
//        return true;
//}
//DEFINE_validator(i8254x, &Validate8254x);