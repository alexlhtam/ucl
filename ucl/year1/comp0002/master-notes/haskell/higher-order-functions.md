a function is called higher-order if it takes a function as an argument or returns a function as a result.
```hs
twice :: (a -> a) -> a -> a
twice f x = f(f x)
```
- twice is higher-order because it takes a function as its first argument