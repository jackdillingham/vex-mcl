# Vex Monte-Carlo Localization
This repository features a library you can use, pairing with PROS and LemLib, to help and provide more accurate tracking data for your autonomous routines. It uses a system of distance sensors to look at how far away the wall is, compares it to a prediction, weights the values, then comes up with a guess. Afterwards, it will call `chassis.setPose();` to apply them back to your routines, as to allow you programs to continue without too much change.

## Required Items
coming soon
