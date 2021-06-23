#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;
using namespace boost::asio;

int main()
{
  io_service ioservice1;
  io_service ioservice2;

  steady_timer timer1{ioservice1, std::chrono::seconds{3}};
  timer1.async_wait([](const boost::system::error_code& __unused ec)
    { cout << "service1: 3 seconds." << endl; });

  steady_timer timer2{ioservice2, std::chrono::seconds{3}};
  timer2.async_wait([](const boost::system::error_code& __unused ec)
    { cout << "service2: 3 seconds." << endl; });

  thread thread1{[&ioservice1](){ ioservice1.run(); }};
  thread thread2{[&ioservice2](){ ioservice2.run(); }};
  thread1.join();
  thread2.join();
}
