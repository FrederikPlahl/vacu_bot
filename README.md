# vacu_bot
ROS Project for lecture

### Installation:

First clone repository in your ``<your_ws>/src``:

```bash
cd ~/<your_ws>/src
git clone https://github.com/FrederikPlahl/vacuum_bot_robolab.git
```

Then build it:

```bash
cd ..
catkin_make
```

### Launch:

Launch model with these commands after sourcing your Workspace:

```bash
roslaunch vacu_bot display_vacu_bot.launch
```

or


```bash
roslaunch vacu_bot simulate_vacu_bot.launch
```

or


```bash
roslaunch vacu_bot simulate_vacu_bot_nav.launch
```

Clone [this][worlds] in your to your PC and extract ``Dataset-of-Gazebo-Worlds-Models-and-Maps/worlds/small_house/small_house.zip``. Now copy the models of the and the world in your gazebo folder.

```bash
sudo cp <path_to_unzipped_small_house>/models/. /usr/share/gazebo-9/models
sudo cp <path_to_unzipped_small_house>/small_house.world /usr/share/gazebo-9/worlds
```

[worlds]: https://github.com/mlherd/Dataset-of-Gazebo-Worlds-Models-and-Maps
