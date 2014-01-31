/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (C) 2014 Named Data Networking Project
 * See COPYING for copyright and distribution information.
 */

#include "tcp-face.hpp"

namespace nfd {

NFD_LOG_INCLASS_TEMPLATE_SPECIALIZATION_DEFINE(StreamFace, TcpFace::protocol, "TcpFace");

TcpFace::TcpFace(const shared_ptr<TcpFace::protocol::socket>& socket)
  : StreamFace<protocol>(socket)
{
}

void
TcpFace::sendInterest(const Interest& interest)
{
  m_socket->async_send(boost::asio::buffer(interest.wireEncode().wire(),
                                           interest.wireEncode().size()),
                       bind(&TcpFace::handleSend, this, _1, interest.wireEncode()));

  // anything else should be done here?
}

void
TcpFace::sendData(const Data& data)
{
  m_socket->async_send(boost::asio::buffer(data.wireEncode().wire(),
                                           data.wireEncode().size()),
                       bind(&TcpFace::handleSend, this, _1, data.wireEncode()));

  // anything else should be done here?
}

} // namespace nfd
