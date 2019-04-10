==========================================
FogLAMP Telegram notification delivery plugin
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
To build FogLAMP "Telegram notification" C++ plugin:

.. code-block:: console

  $ mkdir build
  $ cd build
  $ cmake ..
  $ make

- By default the FogLAMP develop package header files and libraries
  are expected to be located in /usr/include/foglamp and /usr/lib/foglamp
- If **FOGLAMP_ROOT** env var is set and no -D options are set,
  the header files and libraries paths are pulled from the ones under the
  FOGLAMP_ROOT directory.
  Please note that you must first run 'make' in the FOGLAMP_ROOT directory.

You may also pass one or more of the following options to cmake to override 
this default behaviour:

- **FOGLAMP_SRC** sets the path of a FogLAMP source tree
- **FOGLAMP_INCLUDE** sets the path to FogLAMP header files
- **FOGLAMP_LIB sets** the path to FogLAMP libraries
- **FOGLAMP_INSTALL** sets the installation path of Random plugin

NOTE:
 - The **FOGLAMP_INCLUDE** option should point to a location where all the FogLAMP 
   header files have been installed in a single directory.
 - The **FOGLAMP_LIB** option should point to a location where all the FogLAMP
   libraries have been installed in a single directory.
 - 'make install' target is defined only when **FOGLAMP_INSTALL** is set

Examples:

- no options

  $ cmake ..

- no options and FOGLAMP_ROOT set

  $ export FOGLAMP_ROOT=/some_foglamp_setup

  $ cmake ..

- set FOGLAMP_SRC

  $ cmake -DFOGLAMP_SRC=/home/source/develop/FogLAMP  ..

- set FOGLAMP_INCLUDE

  $ cmake -DFOGLAMP_INCLUDE=/dev-package/include ..
- set FOGLAMP_LIB

  $ cmake -DFOGLAMP_LIB=/home/dev/package/lib ..
- set FOGLAMP_INSTALL

  $ cmake -DFOGLAMP_INSTALL=/home/source/develop/FogLAMP ..

  $ cmake -DFOGLAMP_INSTALL=/usr/local/foglamp ..

******************************************
Packaging for 'Telegram notification' plugin 
******************************************

This repo contains the scripts used to create a foglamp-notify-telegram Debian package.

The make_deb script
===================

Run the make_deb command after compiling the plugin:

.. code-block:: console

  $ ./make_deb help
  make_deb [help|clean|cleanall]
  This script is used to create the Debian package of FoglAMP C++ 'Telegram notification' plugin
  Arguments:
   help     - Display this help text
   clean    - Remove all the old versions saved in format .XXXX
   cleanall - Remove all the versions, including the last one
  $

Building a Package
==================

Finally, run the ``make_deb`` command:

.. code-block:: console

   $ ./make_deb
   The package root directory is                : /home/ubuntu/source/foglamp-notify-telegram
   The FogLAMP required version                 : >=1.5
   The Service notification required version    : >=1.5.2
   The package will be built in                 : /home/ubuntu/source/foglamp-notify-telegram/packages/build
   The architecture is set as                   : x86_64
   The package name is                          : foglamp-notify-telegram-1.5.2-x86_64

   ....

   Populating the package and updating version file...Done.
   Building the new package...
   dpkg-deb: building package 'foglamp-notify-telegram' in 'foglamp-notify-telegram-1.0.0-x86_64.deb'.
   Building Complete.
   $

Cleaning the Package Folder
===========================

Use the ``clean`` option to remove all the old packages and the files used to make the package.

Use the ``cleanall`` option to remove all the packages and the files used to make the package.
