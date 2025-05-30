/*
 * Deskflow -- mouse and keyboard sharing utility
 * SPDX-FileCopyrightText: (C) 2025 Chris Rizzitello <sithlord48@gmail.com>
 * SPDX-FileCopyrightText: (C) 2024 Symless Ltd.
 * SPDX-License-Identifier: GPL-2.0-only WITH LicenseRef-OpenSSL-Exception
 */

#include "CommandProcessTests.h"

#include "gui/core/CommandProcess.h"

void CommandProcessTests::runCommand()
{
  // it seems that on windows, you can sometimes just call echo (this worked
  // with windows 2022), but on windows 10 you can't call echo directly.
#if defined(Q_OS_WIN)
  const QString command = "cmd";
  const QStringList arguments = {"/C", "echo Hello, World!"};
  const QString input = "";
#elif defined(Q_OS_UNIX)
  const QString command = "echo";
  const QStringList arguments = {"Hello, World!"};
  const QString input = "";
#endif // Q_OS_WIN

  CommandProcess commandProcess(command, arguments, input);

  const QString actual = commandProcess.run();

  QCOMPARE(actual.toStdString(), "Hello, World!");
}

QTEST_MAIN(CommandProcessTests)
