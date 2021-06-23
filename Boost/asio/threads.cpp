#include <boost/asio/io_service.hpp>
#include <boost/asio/steady_timer.hpp>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;
using namespace boost::asio;

int main()
{
  io_service ioservice;

  steady_timer timer1{ioservice, std::chrono::seconds{3}};
  timer1.async_wait([](const boost::system::error_code& __unused ec)
    { cout << "timer1: 3 seconds." << endl; });

  steady_timer timer2{ioservice, std::chrono::seconds{3}};
  timer2.async_wait([](const boost::system::error_code& __unused ec)
    { cout << "timer2: 3 seconds." << endl; });

  thread thread1{[&ioservice](){ ioservice.run(); }};
  thread thread2{[&ioservice](){ ioservice.run(); }};
  thread1.join();
  thread2.join();
}
