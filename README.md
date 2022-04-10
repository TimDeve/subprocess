# SubProcess for [Carp](https://github.com/carp-lang/Carp)

DO NOT USE: will dead-lock on long outputs...

```clojure
(load "https://github.com/TimDeve/subprocess@master")

(defn main []
  (let-do [res (SubProcess.cmd &[@"sh" @"-c" @"echo this is stderr 1>&2; echo this is stdout; exit 42"])]
    (println* "out       >>> " (SubProcess.out &res))
    (println* "err       >>> " (SubProcess.err &res))
    (println* "exit-code >>> " (SubProcess.exit-code &res))))
```

