
function allSubarraysBruteForce(array)
    # brute force method
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
    # utility function to add value to arrray at key in dictionary d or create empty array and then add value
    d[key] = push!(get(d, key, []), value)
end

function allSubarraysMultimap(array)
    # second way to get subarrays
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

# create new array with numbers
numbers = [1, -1, 2, -1, 0, 1]
println("Array: $numbers")

# print results for brute force method
println("Brute Force:")
allSubarraysBruteForce(numbers)

# print results from multimap method
println("Multimap:")
allSubarraysMultimap(numbers)

