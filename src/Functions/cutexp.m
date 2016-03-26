function datacut = cutexp(data, t_start, t_end)

    ts = 1/200;
    
    [~ ,index_start] = min(abs(data.t-t_start));
    [~, index_end] = min(abs(data.t-t_end));
    
    datacut = struct;
    
    datacut.t = 0:ts:t_end-t_start;
    datacut.v = data.v(index_start:index_end);
    datacut.i = data.i(index_start:index_end);
    datacut.x = data.x(index_start:index_end);
    datacut.xv = data.xv(index_start:index_end);
    
    if length(datacut.t) < length(datacut.v)
        datacut.t = [datacut.t datacut.t(end)+ts];
    end

end