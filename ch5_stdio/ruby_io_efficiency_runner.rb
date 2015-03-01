require 'benchmark'


Benchmark.bmbm do |bm|
  bm.report("by char:") { system("./eff_check_char < sample_input.txt > /dev/null") }
  bm.report("by line") { system("./eff_check_line < sample_input.txt > /dev/null") }
end

