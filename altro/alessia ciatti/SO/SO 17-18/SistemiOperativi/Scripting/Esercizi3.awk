#!/bin/bash

{
	
	if ($2 == "+") print $1+$3
	if ($2 == "-") print $1-$3
	if ($2 == "*") print $1*$3
	if ($2 == "/") print $1/$3

}