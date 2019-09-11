==========================================
Fledge Telegram notification delivery plugin
==========================================

A simple Telegram notification delivery plugin.

The plugin uses the simple Telegram BOT API (HTTPS) to send notification
messages to a Telegram user who has already created a BOT using BothFather via Telegram mobile/destkop app.

The plugin needs the BOT API token, something like 110201543:AAHdqTcvCH1vGWJxfSeofSAs0K5PALDsaw
and the chat_id of the Telegram user, example: 123456789

The HTTPS API message is created this way:

https://api.telegram.org/bot$TOKEN/sendMessage?chat_id=$ID&text=ABCD

using some fake data:

https://api.telegram.org/bot110201543:AAHdqTcvCH1vGWJxfSeofSAs0K5PALDsaw/sendMessage?chat_id=123456789&text=AlertMessage

Telegram resources:
- Create a BOT
  - https://core.telegram.org/bots
  - https://core.telegram.org/bots#6-botfather
  - https://core.telegram.org/bots/api#sendmessage
- Get chat_id
  - Send a message to the new created BOT
  - https://api.telegram.org/bot<YourBOTToken>/getUpdates
    "chat":{"id":123456, ....}

Installation
------------

 The plugin can be installed with given `requirements.sh <requirements.sh>`_ or the following steps:


.. code-block:: bash

  $ sudo apt install -y libcurl4-openssl-dev

Build
-----
To build Fledge "Telegram notification" C++ plugin:

.. code-block:: console

  $ mkdir build
  $ cd build
  $ cmake ..
  $ make

- By default the Fledge develop package header files and libraries
  are expected to be located in /usr/include/fledge and /usr/lib/fledge
- If **FLEDGE_ROOT** env var is set and no -D options are set,
  the header files and libraries paths are pulled from the ones under the
  FLEDGE_ROOT directory.
  Please note that you must first run 'make' in the FLEDGE_ROOT directory.

You may also pass one or more of the following options to cmake to override 
this default behaviour:

- **FLEDGE_SRC** sets the path of a Fledge source tree
- **FLEDGE_INCLUDE** sets the path to Fledge header files
- **FLEDGE_LIB sets** the path to Fledge libraries
- **FLEDGE_INSTALL** sets the installation path of Random plugin

NOTE:
 - The **FLEDGE_INCLUDE** option should point to a location where all the Fledge 
   header files have been installed in a single directory.
 - The **FLEDGE_LIB** option should point to a location where all the Fledge
   libraries have been installed in a single directory.
 - 'make install' target is defined only when **FLEDGE_INSTALL** is set

Examples:

- no options

  $ cmake ..

- no options and FLEDGE_ROOT set

  $ export FLEDGE_ROOT=/some_fledge_setup

  $ cmake ..

- set FLEDGE_SRC

  $ cmake -DFLEDGE_SRC=/home/source/develop/Fledge  ..

- set FLEDGE_INCLUDE

  $ cmake -DFLEDGE_INCLUDE=/dev-package/include ..
- set FLEDGE_LIB

  $ cmake -DFLEDGE_LIB=/home/dev/package/lib ..
- set FLEDGE_INSTALL

  $ cmake -DFLEDGE_INSTALL=/home/source/develop/Fledge ..

  $ cmake -DFLEDGE_INSTALL=/usr/local/fledge ..
