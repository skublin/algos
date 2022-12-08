
function allSubarraysBruteForce(array)
    l = length(array)

    for i in 1:l
        total = 0
        for j in i:l
            total += array[j]
            if total == 0
                println("Sublist ($i, $j).")
            end
        end
    end
end

function insert(d, key, value)
    d[key] = push!(get(d, key, []), value)
end

function allSubarraysMultimap(array)
    d = Dict()

    insert(d, 1, -1)
    
    l = length(array)
    total = 0

    for i in 1:l
        total += array[i]
        
        if total in keys(d)
            lst = d[total]

            for value in lst
                v = value + 1
                println("Sublist ($v, $i).")
            end
        end

        insert(d, total, i)
    end
end

numbers = [1, -1, 2, -1, 0, 1]
println("Array: $numbers")

println("Brute Force:")
allSubarraysBruteForce(numbers)

println("Multimap:")
allSubarraysMultimap(numbers)

