# vacu_bot
ROS Project for lecture

### Installation:

First clone repository in your ``<your_ws>/src``:

``bash
cd ~/<your_ws>/src
git clone https://github.com/FrederikPlahl/vacuum_bot_robolab.git
``

Then build it:

``bash
cd ..
catkin_make
``

### Launch:

Launch model with these commands after sourcing your Workspace:

``bash
roslaunch vacu_bot display_vacu_bot.launch
``

or


``bash
roslaunch vacu_bot simulate_vacu_bot.launch
``

or


``bash
roslaunch vacu_bot simulate_vacu_bot_nav.launch
``
