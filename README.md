SpaceBound
============

SpaceBound is a lightweight spaceshooter type game developed in C++, using the [LiteEngine2D](https://github.com/maritim/LiteEngine2D) game engine.

## Table of contents

* [Download](#get-the-project-from-github)
* [Install dependencies](#install-and-configure-dependecies)
* [Controls](#controls)

Get the project from GitHub
===========================

Directly from this page
-----------------------

* Download the entire project as a **.zip** archive from the top-right button

Using command line
------------------

* Install git

        sudo apt-get install -y git

* Create a local directory for the project

        mkdir SpaceBound && cd SpaceBound

* Clone the project

        git clone https://github.com/ovidiu-giorgi/SpaceBound

Install and configure dependecies
=================================

* Install dependecies from command line

        sudo chmod +x setup.sh
        sudo ./setup.sh

* Compile the project

        make

* Run the application

        ./SpaceBound.out

Controls
========

* W, A, S, D to move.
* L to shoot.
* ESC to exit.
* R to restart the game after you die.
