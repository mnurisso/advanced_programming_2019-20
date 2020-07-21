# IDL - PLUTO

## PLOAD

Can read .dbl , .flt , .vtk , .dbl.h5 , .flt.h5 or .hdf5 formats. It requires also grid.out , dbl.out , flt.out, where one is the grid definition, the other one depends on the format chosen for the visualisation. 

```
PLOAD, 10, /VTK, VAR="bx1", dir="Data/";
```

Four common blocks are initialized when PLOAD is called:

- PLUTO_GRID: grid info number of points (nx1,nx2,nx3), coordinates (x1,x2,x3) and mesh spacing (dx1, dx2, dx3)
- PLUTO_VAR: NVAR and variables with the same name that they've in PLUTO
- PLUTO_RUN: t, dt, nlast
- PLUTO_USERDEF: optional block that can contain user-def variables. They've to be introduced with MATCH_USERDEF_VARNAME to manually add them. A userdef.pro file has to be added in the local working directory 

```
COMMON PLUTO_USERDEF, flag, vort; Define the common block

PRO MATCH_USERDEF_VARNAME, vpt, name, silent=silent
	COMMON PLUTO_GRID
	COMMON PLUTO_VAR
	COMMON PLUTO_RUN
	COMMON PLUTO_USERDEF

	CASE name OF
		"flag": BEGIN flag = vpt & PRINT,"> Reading ",name & END
		"vort": BEGIN vort = vpt & PRINT,"> Reading ",name & END
	ELSE:
	ENDCASE

	vpt = 0; Free memory
END
```

The example will add flag and vort variables so that PLOAD will be able to ream them. Both userdef.pro and pload.pro must be compiled first:

```
.r pload
.r userdef
```

## DISPLAY

```
DISPLAY,x1=x1,x2=x2,alog10(rho), title=’Density’,/vbar
```

PLUTO variables can be used in simple evaluation before being plotted

```
DISPLAY,x1=x1,x2=x2,/VBAR,title='Magnetic Field',bx1^2+bx2^2
```

## VECFIELD

Produces a 2D velocity field plot.

```
VECFIELD,bx1,bx2,x1,x2,/OVERPLOT,col=120
```

## Save file 

The GET_FRAME routine allows to save a window's content to an image file.

```
GET_FRAME, name = "rho", /jpg
```

## Particles

### PARTICLES_LOAD

Load Particles file:

```
PARTICLES_LOAD,10,/VTK
```

### PRINT

Allows to print single data value from a specific particles

```
PRINT,particles[4].vx1
```

### PARTICLES_OPLOT

Overlay point particles on a preexisting 2D plot.

```
PLOAD, 10                    ; Load fluid data file (in .dbl format)
DISPLAY,rho, x1=x1, x2=x2    ; Display density
PARTICLES_LOAD, 10           ; Load particle data file (int .dbl format)
PARTICLES_OPLOT, particles   ; Overlay particles on the plot generated
                             ; by previous DISPLAY call.
```

## Tools

### PCURL, PGRAD, PDIV

```
J = PCURL(Bx1,Bx2,Bx3)
```

