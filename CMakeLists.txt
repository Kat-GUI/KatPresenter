cmake_minimum_required(VERSION 3.16)
project(KatPresenter)

set(CMAKE_CXX_STANDARD 11)

add_executable(KatPresenter test.cpp src/Presenter.h src/D2DPresenter.h)