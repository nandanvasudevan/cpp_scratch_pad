# Testing GUID generators

The libraries tested here are:
 1. Boost::uuid
 2. libuuid (linux)

The question I would like the answer for is '*Does it really matter?*'.

[Benchmark results](output.md)

# Summary
- Use the POSIX time based generators if you just need a UUID.
  - Do not use the random as it is significantly slower!
- As long as you don't need random UUIDs, go with POSIX (if available to you).
  - `Boost` does the better job with random UUID generation.