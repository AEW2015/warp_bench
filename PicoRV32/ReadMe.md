PicoRV32 - A Size-Optimized RISC-V CPU
======================================
The following dhrystone benchmark results are for a core with enabled
`ENABLE_FAST_MUL`, `ENABLE_DIV`, and `BARREL_SHIFTER` options.

Dhrystone benchmark results: 0.516 DMIPS/MHz (908 Dhrystones/Second/MHz)

For the Dhrystone benchmark the average CPI is 4.100.

Without using the look-ahead memory interface (usually required for max
clock speed), this results drop to 0.305 DMIPS/MHz and 5.232 CPI.

Evaluation: Timing and Utilization on Xilinx 7-Series FPGAs
-----------------------------------------------------------

The following evaluations have been performed with Vivado 2017.3.

#### Timing on Xilinx 7-Series FPGAs

The `picorv32_axi` module with enabled `TWO_CYCLE_ALU` has been placed and
routed for Xilinx Artix-7T, Kintex-7T, Virtex-7T, Kintex UltraScale, and Virtex
UltraScale devices in all speed grades. A binary search is used to find the
shortest clock period for which the design meets timing.

See `make table.txt` in [scripts/vivado/](scripts/vivado/).

| Device                    | Device               | Speedgrade | Clock Period (Freq.) |
|:------------------------- |:---------------------|:----------:| --------------------:|
| Xilinx Kintex-7T          | xc7k70t-fbg676-2     | -2         |     2.4 ns (416 MHz) |
| Xilinx Kintex-7T          | xc7k70t-fbg676-3     | -3         |     2.2 ns (454 MHz) |
| Xilinx Virtex-7T          | xc7v585t-ffg1761-2   | -2         |     2.3 ns (434 MHz) |
| Xilinx Virtex-7T          | xc7v585t-ffg1761-3   | -3         |     2.2 ns (454 MHz) |
| Xilinx Kintex UltraScale  | xcku035-fbva676-2-e  | -2         |     2.0 ns (500 MHz) |
| Xilinx Kintex UltraScale  | xcku035-fbva676-3-e  | -3         |     1.8 ns (555 MHz) |
| Xilinx Virtex UltraScale  | xcvu065-ffvc1517-2-e | -2         |     2.1 ns (476 MHz) |
| Xilinx Virtex UltraScale  | xcvu065-ffvc1517-3-e | -3         |     2.0 ns (500 MHz) |
| Xilinx Kintex UltraScale+ | xcku3p-ffva676-2-e   | -2         |     1.4 ns (714 MHz) |
| Xilinx Kintex UltraScale+ | xcku3p-ffva676-3-e   | -3         |     1.3 ns (769 MHz) |
| Xilinx Virtex UltraScale+ | xcvu3p-ffvc1517-2-e  | -2         |     1.5 ns (666 MHz) |
| Xilinx Virtex UltraScale+ | xcvu3p-ffvc1517-3-e  | -3         |     1.4 ns (714 MHz) |

#### Utilization on Xilinx 7-Series FPGAs

The following table lists the resource utilization in area-optimized synthesis
for the following three cores:

- **PicoRV32 (small):** The `picorv32` module without counter instructions,
  without two-stage shifts, with externally latched `mem_rdata`, and without
  catching of misaligned memory accesses and illegal instructions.

- **PicoRV32 (regular):** The `picorv32` module in its default configuration.

- **PicoRV32 (large):** The `picorv32` module with enabled PCPI, IRQ, MUL,
  DIV, BARREL_SHIFTER, and COMPRESSED_ISA features.

See `make area` in [scripts/vivado/](scripts/vivado/).

| Core Variant       | Slice LUTs | LUTs as Memory | Slice Registers |
|:------------------ | ----------:| --------------:| ---------------:|
| PicoRV32 (small)   |        761 |             48 |             442 |
| PicoRV32 (regular) |        917 |             48 |             583 |
| PicoRV32 (large)   |       2019 |             88 |            1085 |
