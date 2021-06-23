#include <boost/asio/buffer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>
#include <ctime>
#include <string>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

io_service ioservice;
tcp::endpoint tcp_endpoint{tcp::v4(), 2014};
tcp::acceptor tcp_acceptor{ioservice, tcp_endpoint};
tcp::socket tcp_socket{ioservice};
string datum;

void write_handler(const boost::system::error_code &ec,
                   size_t __unused bytes_transferred) {
  if (!ec)
    tcp_socket.shutdown(tcp::socket::shutdown_send);
}

void accept_handler(const boost::system::error_code &ec) {
  if (!ec) {
    time_t now = time(nullptr);
    datum = ctime(&now);
    async_write(tcp_socket, buffer(datum), write_handler);
  }
}

int main() {
  tcp_acceptor.listen();
  tcp_acceptor.async_accept(tcp_socket, accept_handler);
  ioservice.run();
}
