# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program



##Describe the effect each of the P, I, D components had in your implementation.

###P — Proportional
This component contributes to the steering angle in a way that the car steers opposite direction of the error i.e. towards to the trajectory. This is absolutely required component in this particular exercise, though as I describe below it should be compensated by other components

###I — Integral
This component is meant to smoothen the oscillation to the best of my understanding. In this particular exercise I didn't observe benefits of it and left it as 0.0

###D — Differential
This component increases as the error does so, hence it's compensating the oscillations according to the growth of deviation from the trajectory. In this particular case it has the most significant weight


##Describe how the final hyperparameters were chosen.

I tuned parameters manually as described below:

pid.Init(0.0, 0.1, 0.0);

Non-zero Integral values are cumulatively increasing amplitude of trajectory ‘swing’, shortly making the car off the track, hence I didn’t find it useful, and left it 0.0

pid.Init(0.1, 0.0, 0.0);

Proportional value of 0.1 with zero Inregral and Differential made a good job on the initial straight, though on the first curve as CTE increased the turns were growing proportionally, but more then necessary, leading to divergent oscillations of the car

pid.Init(0.1, 0.0, 0.1);

I’ve retained the Proportinal value at 0.1 and added Differential as 0.1. The previous symptom remained but the trajectory was slightly better

pid.Init(0.1, 0.0, 2.0);

By trial and error I’ve concluded Differential coefficient to be 2.0
The car is slightly swinging on turns though consistently passes the circuit

[This is the video of the latter parameters](./pid480.mov)