# THERE IS NO ELIXIR COMPILER ON HACKER HANK FOR THIS ONE YET

defmodule Solution do
  def read do
    case IO.read(:stdio, :line) do
      :eof ->
        :ok

      {:error, reason} ->
        IO.puts("Error: #{reason}")

      data ->
        String.replace_trailing(data, "\n", "")
    end
  end

  def write(answer) do
    answer = answer |> Integer.to_string() |> to_charlist()
    :ok = IO.write(answer)
  end

  def solve() do
    _steps = read() |> String.to_integer()
    path = read()

    answer = walk(path, 0, 0)

    write(answer)
  end

  defp walk("", _state, answer), do: answer
  defp walk("U" <> rest, -1, answer), do: walk(rest, 0, answer + 1)
  defp walk("D" <> rest, level, answer), do: walk(rest, level - 1, answer)
  defp walk("U" <> rest, level, answer), do: walk(rest, level + 1, answer)
end

Solution.solve()
