for (int i = 0; i < field.size(); i++)
    {
        for (int j = 0; j < field[i].size(); j++)
        {
            if (field[i][j] == -2)
            {
                field[i][j] = 0;
            }
        }
    }