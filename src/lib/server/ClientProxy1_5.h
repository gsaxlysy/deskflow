/*
 * Deskflow -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2013 - 2016 Symless Ltd.
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#pragma once

#include "server/ClientProxy1_4.h"

#include <vector>

class Server;
class IEventQueue;

//! Proxy for client implementing protocol version 1.5
class ClientProxy1_5 : public ClientProxy1_4
{
public:
  ClientProxy1_5(const std::string &name, deskflow::IStream *adoptedStream, Server *server, IEventQueue *events);
  ClientProxy1_5(ClientProxy1_5 const &) = delete;
  ClientProxy1_5(ClientProxy1_5 &&) = delete;
  ~ClientProxy1_5() override = default;

  ClientProxy1_5 &operator=(ClientProxy1_5 const &) = delete;
  ClientProxy1_5 &operator=(ClientProxy1_5 &&) = delete;

  void sendDragInfo(uint32_t fileCount, const char *info, size_t size) override;
  void fileChunkSending(uint8_t mark, char *data, size_t dataSize) override;
  bool parseMessage(const uint8_t *code) override;
  void fileChunkReceived() const;
  void dragInfoReceived() const;

private:
  IEventQueue *m_events;
};
