#define var FT_USER & make login part of it
#put var FT_USER into the env
#make $FT_USER part of the list of groups
#list groups
#format by commas w/o spaces (man tr)
#

#FT_USER=$USER
#export FT_USER
#
