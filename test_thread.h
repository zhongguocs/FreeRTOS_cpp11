/// @file
///
/// @author: Piotr Grygorczuk grygorek@gmail.com
///
/// @copyright Copyright 2019 Piotr Grygorczuk
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
///
/// o Redistributions of source code must retain the above copyright notice,
///   this list of conditions and the following disclaimer.
///
/// o Redistributions in binary form must reproduce the above copyright notice,
///   this list of conditions and the following disclaimer in the documentation
///   and/or other materials provided with the distribution.
///
/// o My name may not be used to endorse or promote products derived from this
///   software without specific prior written permission.
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
///

#ifndef __THREAD_TEST_H__
#define __THREAD_TEST_H__

#include <thread>
#include <chrono>

inline void DetachBeforeThreadEnd()
{
  using namespace std::chrono_literals;
  std::thread t{[] {
    std::this_thread::sleep_for(1s);
  }};

  t.detach();
}

inline void DetachAfterThreadEnd()
{
  using namespace std::chrono_literals;
  std::thread t{[] {
  }};

  std::this_thread::sleep_for(1s);
  t.detach();
}

inline void JoinBeforeThreadEnd()
{
  using namespace std::chrono_literals;
  std::thread t{[] {
    std::this_thread::sleep_for(1s);
  }};

  t.join();
}

inline void JoinAfterThreadEnd()
{
  using namespace std::chrono_literals;
  std::thread t{[] {
  }};

  std::this_thread::sleep_for(1s);
  t.join();
}

inline void DestroyBeforeThreadEnd()
{
  //using namespace std::chrono_literals;
  // will call std::terminate if enabled
  //	std::thread t{[]{
  //			std::this_thread::sleep_for(1s);
  //	}};
}

inline void DestroyNoStart()
{
  std::thread t;
}

inline void StartAndMoveOperator()
{
  using namespace std::chrono_literals;
  std::thread tt;

  {
    std::thread t{[] {
      std::this_thread::sleep_for(1s);
    }};
    tt = std::move(t);
  }

  tt.join();
}

inline void StartAndMoveConstructor()
{
  using namespace std::chrono_literals;

  std::thread t{[] {
    std::this_thread::sleep_for(1s);
  }};

  std::thread tt{std::move(t)};

  //t.join(); this will terminate the program
  tt.join();
}

#endif //__THREAD_TEST_H__
