/*
 * FCI FC2580 silicon tuner driver
 *
 * Copyright (C) 2012 Antti Palosaari <crope@iki.fi>
 *
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License along
 *    with this program; if not, write to the Free Software Foundation, Inc.,
 *    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef FC2580_H
#define FC2580_H

#include <linux/kconfig.h>
#include "dvb_frontend.h"

/*
 * I2C address
 * 0x56, ...
 */

/**
 * struct fc2580_platform_data - Platform data for the fc2580 driver
 * @clk: Clock frequency (0 = internal clock).
 * @dvb_frontend: DVB frontend.
 */
struct fc2580_platform_data {
	u32 clk;
	struct dvb_frontend *dvb_frontend;
};

struct fc2580_config {
	/*
	 * I2C address
	 * 0x56, ...
	 */
	u8 i2c_addr;

	/*
	 * clock
	 */
	u32 clock;
};

#if IS_ENABLED(CONFIG_MEDIA_TUNER_FC2580)
extern struct dvb_frontend *fc2580_attach(struct dvb_frontend *fe,
	struct i2c_adapter *i2c, const struct fc2580_config *cfg);
#else
static inline struct dvb_frontend *fc2580_attach(struct dvb_frontend *fe,
	struct i2c_adapter *i2c, const struct fc2580_config *cfg)
{
	pr_warn("%s: driver disabled by Kconfig\n", __func__);
	return NULL;
}
#endif

#endif
