# Benchmark results

## Random UUID generator

<details open>
<summary> Benchmark results </summary>

```
benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
[boost] Simple random                          100            57     4.4517 ms
                                        789.205 ns    788.535 ns    790.496 ns
                                        4.56001 ns    2.77613 ns    7.80473 ns

[boost] Bulk generator                         100           314     4.3646 ms
                                         129.05 ns    128.239 ns    130.693 ns
                                        5.64547 ns    3.01659 ns    9.36629 ns

POSIX                                          100            17      4.556 ms
                                        2.76651 us    2.75983 us    2.78283 us
                                        50.2018 ns     25.296 ns    104.656 ns


===============================================================================
```
</details>
