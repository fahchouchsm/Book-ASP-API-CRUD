cmake_minimum_required(VERSION 3.25)
project(tpFact C)

set(CMAKE_C_STANDARD 11)

add_executable(fac_client fac_client.c fac_clnt.c fac_xdr.c)
add_executable(fac_server fac_server.c fac_svc.c fac_xdr.c)
