#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_WTRV()
{
	Identifier = "DEFAULT_PT_WTRV";
	Name = "WTRV";
	Colour = PIXPACK(0xA0A0FF);
	MenuVisible = 1;
	MenuSection = SC_GAS;
	Enabled = 1;

	Advection = 1.0f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.99f;
	Loss = 0.30f;
	Collision = -0.1f;
	Gravity = -0.1f;
	Diffusion = 0.75f;
	HotAir = 0.0003f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 4;

	Weight = 1;

	DefaultProperties.temp = R_TEMP + 100.0f + 273.15f;
	HeatConduct = 78;
	Description = "Steam. Produced from hot water.";

	Properties = TYPE_GAS | PROP_WATER;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 371.0f;
	LowTemperatureTransition = ST;
	HighTemperature = ITH;
	HighTemperatureTransition = NT;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS)
{


	// the best transition to ctype that you've ever seen (made while drunkj)

	if (parts[i].ctype != 0 && sim->elements[parts[i].ctype].HighTemperature != ITH && sim->elements[parts[i].ctype].HighTemperature != ST && parts[i].temp - sim->pv[y / CELL][x / CELL] < sim->elements[parts[i].ctype].HighTemperature && RNG::Ref().chance(sim->elements[parts[i].ctype].HighTemperature - 100, restrict_flt(parts[i].temp - sim->pv[y / CELL][x / CELL], sim->elements[parts[i].ctype].HighTemperature, MAX_TEMP)))
	{



		sim->part_change_type(i, x, y, parts[i].ctype);
		if (parts[i].tmpcity[6] != 0)
			parts[i].ctype = parts[i].tmpcity[6];
		else
			parts[i].ctype = 0;
		return 1;
	}


int r, rx, ry;
	
		for (ry=-1; ry<2; ry++)
			for (rx = -1; rx < 2; rx++)
			if (BOUNDS_CHECK && (rx || ry))
			{
				r = pmap[y + ry][x + rx];
				if (!r)
				{
				if(parts[i].water > 50)

				continue;
				}
				if ((TYP(r)==PT_RBDM||TYP(r)==PT_LRBD) && !sim->legacy_enable && parts[i].temp>(273.15f+12.0f) && RNG::Ref().chance(1, 100))
				{
					sim->part_change_type(i,x,y,PT_FIRE);
					parts[i].life = 4;
					parts[i].ctype = PT_WATR;
				}
			}
	if(parts[i].temp>1273&&parts[i].ctype==PT_FIRE)
		parts[i].temp-=parts[i].temp/1000;
	return 0;
}
