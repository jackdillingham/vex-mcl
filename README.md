# Vex Monte-Carlo Localization
This repository features a library you can use, pairing with PROS and LemLib, to help and provide more accurate tracking data for your autonomous routines. It uses a system of distance sensors to look at how far away the wall is, compares it to a prediction, weights the values, then comes up with a guess. Afterwards, it will call `chassis.setPose();` to apply them back to your routines, as to allow you programs to continue without too much change.

## Required Items

- A PROS V5 project with LemLib 0.5.6, Robodash, and a compatible LVGL 8 package.
- Distance sensors with known mounting offsets and headings, plus the field dimensions.

Pass the chassis you already use for autonomous to MCL, along with your configured sensors and field dimensions. Keep the chassis and console alive for as long as MCL uses them.

```cpp
#include "mcl/mcl.hpp"

// Use your project's existing chassis, mclSensors, and fieldDimensions.
rd::Console mclConsole("MCL");
localization::MCL mcl(chassis, mclSensors, fieldDimensions, mclConsole);
```

The constructor is available for integration. Distance-based pose correction is still in development.
