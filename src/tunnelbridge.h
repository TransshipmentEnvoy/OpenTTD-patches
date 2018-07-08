/* $Id$ */

/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file tunnelbridge.h Header file for things common for tunnels and bridges */

#ifndef TUNNELBRIDGE_H
#define TUNNELBRIDGE_H

#include "map_func.h"

void MarkBridgeDirty(TileIndex begin, TileIndex end, DiagDirection direction, uint bridge_height, const ZoomLevel mark_dirty_if_zoomlevel_is_below = ZOOM_LVL_END);
void MarkBridgeDirty(TileIndex tile, const ZoomLevel mark_dirty_if_zoomlevel_is_below = ZOOM_LVL_END);
void MarkBridgeOrTunnelDirty(TileIndex tile, const ZoomLevel mark_dirty_if_zoomlevel_is_below = ZOOM_LVL_END);
void MarkBridgeOrTunnelDirtyOnReservationChange(TileIndex tile, const ZoomLevel mark_dirty_if_zoomlevel_is_below = ZOOM_LVL_END);
uint GetTunnelBridgeSignalSimulationSignalCount(TileIndex begin, TileIndex end);

/**
 * Calculates the length of a tunnel or a bridge (without end tiles)
 * @param begin The begin of the tunnel or bridge.
 * @param end   The end of the tunnel or bridge.
 * @return length of bridge/tunnel middle
 */
static inline uint GetTunnelBridgeLength(TileIndex begin, TileIndex end)
{
	int x1 = TileX(begin);
	int y1 = TileY(begin);
	int x2 = TileX(end);
	int y2 = TileY(end);

	return abs(x2 + y2 - x1 - y1) - 1;
}

extern TileIndex _build_tunnel_endtile;

#endif /* TUNNELBRIDGE_H */
