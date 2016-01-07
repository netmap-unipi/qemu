/*
 * Copyright (c) Universita' di Pisa.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef PTNETMAP_H
#define PTNETMAP_H

#include <net/if.h>
#include "net/netmap.h"
#include "net/net.h"
#include "exec/memory.h"
#include "dev/netmap/netmap_virt.h" /* from netmap sources */

typedef struct ptnetmap_state {
    bool required;                      /* ptnetmap required on this port */
    bool created;                       /* ptnetmap kthreads created */
    struct NetmapState *netmap;
    unsigned long features;             /* ptnetmap features */
    unsigned long acked_features;       /* ptnetmap acked features */
    uint32_t memsize;                     /* netmap memory info */
    void *mem;
    uint32_t offset;
    uint16_t num_tx_rings;
    uint16_t num_rx_rings;
    uint16_t num_tx_slots;
    uint16_t num_rx_slots;
} PTNetmapState;

uint32_t ptnetmap_get_features(PTNetmapState *pt, uint32_t features);
void ptnetmap_ack_features(PTNetmapState *pt, uint32_t features);
int ptnetmap_get_mem(PTNetmapState *pt);
int ptnetmap_get_hostmemid(PTNetmapState *pt);
int ptnetmap_create(PTNetmapState *nc, struct ptnetmap_cfg *conf);
int ptnetmap_delete(PTNetmapState *nc);

int ptnetmap_memdev_create(void *mem_ptr, uint32_t mem_size, uint16_t mem_id);

#endif /* PTNETMAP_H */
