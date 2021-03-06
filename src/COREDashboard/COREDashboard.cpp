#include "COREDashboard.h"

using namespace CORE;

shared_ptr<thread> COREDashboard::m_serveThread;
Server * COREDashboard::m_server;

void COREDashboard::robotInit() {
    m_server = new Server(make_shared<m_logger>()); 
    m_server->addWebSocketHandler("/path", make_shared<COREPathConnectionHandler>());

    m_serveThread = make_shared<thread>([&]{m_server->serve("/home/lvuser/COREWebDashboard/www", 5810);});
}

COREDashboard::~COREDashboard() {
    m_server->terminate();
    m_serveThread->join();
    delete m_server;
}

void COREDashboard::m_logger::log(Logger::Level level, const char *message) {
    if(level == Level::Severe || level == Level::Error) {
        CORELog::logError("COREDashboard: " + string(message));
    } else if(level == Level::Warning) {
        CORELog::logWarning("COREDashboard: " + string(message));
    } else if(level == Level::Info /*|| level == Level::ACCESS || level == Level::DEBUG*/) {
        CORELog::logInfo("COREDashboard: " + string(message));
    }
}

void COREDashboard::postLoopTask() {
}
