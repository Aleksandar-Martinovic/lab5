##############################################################################
## Filename:          C:\materija\RA167-2015\novi\lab5\lab5-master/drivers/my_timer_v1_00_a/data/my_timer_v2_1_0.tcl
## Description:       Microprocess Driver Command (tcl)
## Date:              Tue Apr 24 09:17:10 2018 (by Create and Import Peripheral Wizard)
##############################################################################

#uses "xillib.tcl"

proc generate {drv_handle} {
  xdefine_include_file $drv_handle "xparameters.h" "my_timer" "NUM_INSTANCES" "DEVICE_ID" "C_BASEADDR" "C_HIGHADDR" 
}
