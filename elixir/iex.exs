read = fn ->
  case IO.read(:stdio, :line) do
    :eof ->
      :ok

    {:error, reason} ->
      IO.puts("Error: #{reason}")

    data ->
      IO.write(:stdio, "Hello, World. \n")
      IO.write(:stdio, data)
      read()
  end
end

read.()
