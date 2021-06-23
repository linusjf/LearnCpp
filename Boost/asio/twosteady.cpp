#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <iostream>

using namespace std;
using namespace boost::asio;

int main()
{
  io_service ioservice;

  steady_timer timer1{ioservice, std::chrono::seconds{3}};
  timer1.async_wait([](const boost::system::error_code& __unused ec)
    { cout << "3 seconds." << endl; });

  steady_timer timer2{ioservice, std::chrono::seconds{4}};
  timer2.async_wait([](const boost::system::error_code& __unused ec)
    { cout << "4 seconds." << endl; });

  ioservice.run();
}
