#include <boost/asio/io_service.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/spawn.hpp>
#include <boost/asio/write.hpp>
#include <ctime>
#include <list>
#include <string>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioservice;
tcp::endpoint tcp_endpoint{tcp::v4(), 2014};
tcp::acceptor tcp_acceptor{ioservice, tcp_endpoint};
list<tcp::socket> tcp_sockets;

void do_write(tcp::socket &tcp_socket, yield_context yield) {
  time_t now = time(nullptr);
  string data = ctime(&now);
  async_write(tcp_socket, buffer(data), yield);
  tcp_socket.shutdown(tcp::socket::shutdown_send);
}

void do_accept(yield_context yield) {
  for (int i = 0; i < 2; ++i) {
    tcp_sockets.emplace_back(ioservice);
    tcp_acceptor.async_accept(tcp_sockets.back(), yield);
    spawn(ioservice,
          [](yield_context yield) { do_write(tcp_sockets.back(), yield); });
  }
}

int main() {
  tcp_acceptor.listen();
  spawn(ioservice, do_accept);
  ioservice.run();
}
