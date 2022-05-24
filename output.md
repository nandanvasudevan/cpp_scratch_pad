# Benchmark results

## Random UUID generator

**Verdict**: Boost is considerably faster than the POSIX version.

<details open>
<summary> Benchmark results </summary>

```
benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
[Boost] Simple random                          100            54     4.2066 ms 
                                        785.542 ns    781.083 ns      792.1 ns 
                                        27.2953 ns    20.0852 ns    35.9315 ns 
                                                                               
[Boost] Bulk generator                         100           262     4.1396 ms 
                                        150.429 ns    149.567 ns    151.634 ns 
                                        5.13811 ns    3.97455 ns    6.50275 ns 
                                                                               
[POSIX]                                        100            16     4.3872 ms 
                                        2.73923 us    2.72814 us    2.75811 us 
                                        72.0066 ns    47.3018 ns    103.731 ns 
                                                                               
POSIX                                          100            16      4.256 ms 
                                        2.73204 us    2.72466 us     2.7401 us 
                                        39.3086 ns    34.7881 ns    48.5283 ns 

```
</details>

## String generator

**Verdict**: POSIX version is much faster than boost.

Do note, **MD5 has been cracked and therefore is not safe, despite being the fastest**.

<details open>
<summary> Benchmark results </summary>

```
benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
[Boost] SHA1 - DNS                             100            37     4.6805 ms 
                                        1.21532 us    1.20884 us    1.22894 us 
                                        45.7703 ns    24.7803 ns    78.7038 ns 
                                                                               
[Boost] SHA1 - OID                             100            35      4.634 ms 
                                        1.16141 us    1.15777 us    1.17047 us 
                                        27.4029 ns    13.3546 ns    52.4453 ns 
                                                                               
[Boost] SHA1 - URL                             100            36     4.6872 ms 
                                        1.39152 us    1.36428 us    1.41662 us 
                                        133.335 ns    124.065 ns    138.174 ns 
                                                                               
[Boost] SHA1 - x500                            100            36     4.6908 ms 
                                        1.18244 us    1.17617 us    1.19085 us 
                                        36.6982 ns    29.7689 ns     55.976 ns 
                                                                               
[Boost] MD5 - DNS                              100           132     4.6332 ms 
                                        335.316 ns    332.948 ns    338.177 ns 
                                        13.2208 ns    11.0887 ns    17.2547 ns 
                                                                               
[Boost] MD5 - OID                              100           130      4.628 ms 
                                         344.24 ns    340.678 ns     352.31 ns 
                                        25.9358 ns    14.2823 ns    51.6422 ns 
                                                                               
[Boost] MD5 - URL                              100           132     4.6332 ms 
                                        337.754 ns    335.185 ns    341.339 ns 
                                        15.3451 ns    11.8406 ns    20.5227 ns 
                                                                               
[Boost] MD5 - x500                             100           131     4.6374 ms 
                                        332.783 ns    330.241 ns     335.96 ns 
                                        14.4736 ns    12.1171 ns    19.0118 ns 
                                                                               
[POSIX] SHA1 - DNS                             100           150       4.62 ms 
                                        294.941 ns    294.172 ns    296.229 ns 
                                        4.95704 ns      3.228 ns    8.01401 ns 
                                                                               
[POSIX] SHA1 - OID                             100           149      4.619 ms 
                                        290.169 ns    288.666 ns     291.94 ns 
                                        8.26343 ns    7.06886 ns    10.2555 ns 
                                                                               
[POSIX] SHA1 - URL                             100           149     4.6339 ms 
                                        294.563 ns    293.541 ns    296.129 ns 
                                        6.37704 ns    4.26076 ns    9.76117 ns 
                                                                               
[POSIX] SHA1 - x500                            100           149      4.619 ms 
                                        291.186 ns    289.985 ns    292.502 ns 
                                        6.42244 ns    5.59576 ns    7.91289 ns 
                                                                               
[POSIX] MD5 - DNS                              100           440       4.62 ms 
                                        105.868 ns    105.657 ns    106.312 ns 
                                        1.49578 ns    0.82451 ns    2.41254 ns 
                                                                               
[POSIX] MD5 - OID                              100           428     4.6224 ms 
                                         105.79 ns     105.66 ns    106.093 ns 
                                       0.953504 ns   0.371906 ns    1.64709 ns 
                                                                               
[POSIX] MD5 - URL                              100           442     4.5968 ms 
                                        108.721 ns    108.464 ns    109.294 ns 
                                        1.85311 ns   0.884186 ns    3.28677 ns 
                                                                               
[POSIX] MD5 - x500                             100           437     4.5885 ms 
                                        106.079 ns    105.826 ns    106.622 ns 
                                        1.80445 ns   0.996206 ns    3.22527 ns
```

</details>

## Time based

**Verdict**: By far the fastest method.

Sadly boost does not provide an [easy way](https://stackoverflow.com/questions/58500967/how-do-i-convert-time-uuid-stored-in-boost-uuid-to-a-timestamp-time-since-epoc)
to do this.

<details open>
<summary> Benchmark results</summary>

```
benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
[POSIX] Basic                                  100          2642     7.3976 ms 
                                        28.6437 ns    27.9568 ns    30.4941 ns 
                                        5.35536 ns    2.52625 ns    11.4411 ns 
                                                                               
[POSIX] Safe                                   100          2446      7.338 ms 
                                        30.3731 ns    28.6405 ns      33.56 ns 
                                        11.6607 ns    7.15367 ns    17.4972 ns 

```
</details>